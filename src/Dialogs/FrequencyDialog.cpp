/*
Copyright_License {

  XCSoar Glide Computer - http://www.xcsoar.org/
  Copyright (C) 2000-2021 The XCSoar Project
  A detailed list of copyright holders can be found in the file "AUTHORS".

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
}
*/

#include "Dialogs.h"
#include "Dialogs/WidgetDialog.hpp"
#include "Widget/ListWidget.hpp"
#include "Look/DialogLook.hpp"
#include "UIGlobals.hpp"
#include "Renderer/TextRowRenderer.hpp"
#include "Language/Language.hpp"
#include "ActionInterface.hpp"
#include "Profile/Profile.hpp"
#include "UtilsSettings.hpp"
#include "io/FileLineReader.hpp"
#include "util/ExtractParameters.hpp"
#include "util/StringCompare.hxx"
#include "util/Macros.hpp"
#include "XML/Node.hpp"
#include "XML/DataNodeXML.hpp"
#include "XML/Parser.hpp"

class FrequencyListWidget final
  : public ListWidget {

  const DialogLook &dialog_look;
  TextRowRenderer row_renderer;
  Button *active_button, *standby_button, *cancel_button;

public:
  struct RadioChannel {
	  tstring name;
	  RadioFrequency radio_frequency;
  };
  std::vector<RadioChannel> *channels;

public:
  void CreateButtons(WidgetDialog &dialog);

public:
  FrequencyListWidget(const DialogLook &_dialog_look, std::vector<RadioChannel> *_channels)
    :dialog_look(_dialog_look),
	 channels (_channels) {}

  bool UpdateList() noexcept;

  unsigned GetCursorIndex() const {
    return GetList().GetCursorIndex();
  }

public:
  /* virtual methods from class Widget */
  void Prepare(ContainerWindow &parent, const PixelRect &rc) noexcept override;

  /* virtual methods from class List::Handler */
  void OnPaintItem(Canvas &canvas, const PixelRect rc,
                   unsigned index) noexcept override {
    assert(index < channels->size());

    const RadioChannel& channel = (*channels)[index];

    // Draw name and frequency
    row_renderer.DrawTextRow(canvas, rc, channel.name.c_str());

    if (channel.radio_frequency.IsDefined()) {
    	StaticString<30> buffer;
    	TCHAR radio[20];
      channel.radio_frequency.Format(radio, ARRAY_SIZE(radio));
      buffer.Format(_T("%s MHz"), radio);
      row_renderer.DrawRightColumn(canvas, rc, buffer);
      }

  }

  bool CanActivateItem([[maybe_unused]] unsigned index) const noexcept override {
    return true;
  }

  void OnActivateItem([[maybe_unused]] unsigned index) noexcept override;
};

void
FrequencyListWidget::CreateButtons(WidgetDialog &dialog)
{
  standby_button = dialog.AddButton(_("Set Standby Frequency"), [this](){
    unsigned index = GetCursorIndex();
    assert(index < channels->size());
    const RadioChannel *channel = &(*channels)[index];
    ActionInterface::SetStandbyFrequency(channel->radio_frequency,
            channel->name.c_str());
    cancel_button->Click();
});

  active_button = dialog.AddButton(_("Set Active Frequency"), [this](){
    unsigned index = GetCursorIndex();
    assert(index < channels->size());
    const RadioChannel *channel = &(*channels)[index];
    ActionInterface::SetActiveFrequency(channel->radio_frequency,
            channel->name.c_str());
    cancel_button->Click();
  });

  cancel_button = dialog.AddButton(_("Close"), mrCancel);
}

void
FrequencyListWidget::Prepare(ContainerWindow &parent,
                              const PixelRect &rc) noexcept
{
  CreateList(parent, dialog_look, rc,
             row_renderer.CalculateLayout(*dialog_look.list.font_bold));

  GetList().SetLength(channels->size());
}

void
FrequencyListWidget::OnActivateItem([[maybe_unused]] unsigned index) noexcept
{
  // May still be talking on active frequency
  standby_button->Click();
}

bool
FrequencyListWidget::UpdateList() noexcept
{
  channels->clear();

  auto path = Profile::GetPath(ProfileKeys::FrequenciesFile);
  if (path == nullptr) {
    return false;
  }
//////////////

  // Load root node
  const auto xml_root = XML::ParseFile(path);
  const ConstDataNodeXML root(xml_root);

  // Check if root node is a <FrequencyList> node
  if (!StringIsEqual(root.GetName(), _T("FrequencyList")))
    return false;

  const auto children = xml_root.ListChildrenNamed(_T("Station"));
  for (const auto &i : children) {
	  const TCHAR *name = i.GetAttribute(_T("name"));
	  if (name == nullptr)
	    return;
	  const TCHAR *frequency = i.GetAttribute(_T("frequency"));
	  if (frequency == nullptr)
	    return;

	  RadioFrequency radio_frequency = RadioFrequency::Parse(frequency);
	  if (radio_frequency.IsDefined()) {
	    RadioChannel *channel = new RadioChannel();
	    channel->name = name;
	    channel->radio_frequency = radio_frequency;
	    channels->push_back(*channel);
	  }
  }
  return !channels->empty();
/*  FileLineReader reader(path, Charset::AUTO);

  TCHAR *line;
  while ((line = reader.ReadLine()) != NULL) {

	if (StringIsEmpty(line))
	  continue;

	TCHAR ctemp[4096];
	if (_tcslen(line) >= ARRAY_SIZE(ctemp))
	  // line too long for buffer
	  continue;

	const TCHAR *params[2];
    size_t n_params = ExtractParameters(line, ctemp, params,
                                      ARRAY_SIZE(params), true, _T('"'));
    if (n_params != 2)
      continue;

    RadioFrequency radio_frequency = RadioFrequency::Parse(params[1]);
    if (radio_frequency.IsDefined()) {
      RadioChannel *channel = new RadioChannel();
      channel->name = params[0];
      channel->radio_frequency = radio_frequency;
      channels->push_back(*channel);
    }
  }
  return !channels->empty();
  */
}

void
FrequencyDialogShowModal() noexcept
{
  std::vector<FrequencyListWidget::RadioChannel> channels;

  const DialogLook &look = UIGlobals::GetDialogLook();

  auto widget = std::make_unique<FrequencyListWidget>(look,&channels);
  if (widget->UpdateList() == false) {
	// no channels: don't show the dialog
	return;
  }

  TWidgetDialog<FrequencyListWidget>
    dialog(WidgetDialog::Full{}, UIGlobals::GetMainWindow(),
           look, _("Frequency Card"));
  widget->CreateButtons(dialog);

  dialog.FinishPreliminary(std::move(widget));
  dialog.EnableCursorSelection();
  dialog.ShowModal();

}
