#include "tp_data_features/Globals.h"
#include "tp_data_features/members/SimpleMatchesMember.h"

#include "tp_data/CollectionFactory.h"

namespace tp_data_features
{
TDP_DEFINE_ID(                     featuresSID,                         "Features")
TDP_DEFINE_ID(                      matchesSID,                          "Matches")

//##################################################################################################
void createCollectionFactories(tp_data::CollectionFactory& collectionFactory)
{
  collectionFactory.addMemberFactory(new SimpleMatchesMemberFactory());
}

}
