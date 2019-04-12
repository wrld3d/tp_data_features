TARGET = tp_data_features
TEMPLATE = lib

DEFINES += TDP_DATA_FEATURES_LIBRARY

SOURCES += src/Globals.cpp
HEADERS += inc/tp_data_features/Globals.h

#-- Members ----------------------------------------------------------------------------------------
SOURCES += src/members/FeaturesMember.cpp
HEADERS += inc/tp_data_features/members/FeaturesMember.h

SOURCES += src/members/MatchesMember.cpp
HEADERS += inc/tp_data_features/members/MatchesMember.h

SOURCES += src/members/SimpleMatchesMember.cpp
HEADERS += inc/tp_data_features/members/SimpleMatchesMember.h

