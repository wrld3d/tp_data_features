#ifndef tp_data_features_MatchesMember_h
#define tp_data_features_MatchesMember_h

#include "tp_data_features/Globals.h"

#include "tp_data/AbstractMember.h"

namespace tp_data_features
{

//##################################################################################################
class MatchesMember : public tp_data::AbstractMember
{
public:
  //################################################################################################
  MatchesMember(const std::string& name, const tp_utils::StringID& type);

  //################################################################################################
  ~MatchesMember() override;

};

}

#endif
