# Build rules for the generic utility library

TIME_SRC_DIR = $(SRC)/time

TIME_SOURCES = \
	$(TIME_SRC_DIR)/Zone.cxx \
	$(TIME_SRC_DIR)/Convert.cxx \
	$(TIME_SRC_DIR)/DeltaTime.cpp \
	$(TIME_SRC_DIR)/WrapClock.cpp \
	$(TIME_SRC_DIR)/LocalTime.cpp \
	$(TIME_SRC_DIR)/BrokenTime.cpp \
	$(TIME_SRC_DIR)/BrokenDate.cpp \
	$(TIME_SRC_DIR)/BrokenDateTime.cpp

$(eval $(call link-library,time,TIME))
