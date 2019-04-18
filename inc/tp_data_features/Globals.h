#ifndef tp_data_features_Globals_h
#define tp_data_features_Globals_h

#include "tp_utils/StringID.h"

namespace tp_data
{
class CollectionFactory;
}

//##################################################################################################
//! Base classes for features and matches.
namespace tp_data_features
{
TDP_DECLARE_ID(                     featuresSID,                         "Features")
TDP_DECLARE_ID(                      matchesSID,                          "Matches")

//##################################################################################################
//! Add the collection factories that this module provides to the CollectionFactory
void createCollectionFactories(tp_data::CollectionFactory& collectionFactory);

}

#endif
