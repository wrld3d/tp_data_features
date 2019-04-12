#ifndef tp_data_features_CVFeaturesMember_h
#define tp_data_features_CVFeaturesMember_h

#include "tp_data_features/members/MatchesMember.h"

#include "tp_data/AbstractMemberFactory.h"

#include "glm/glm.hpp"

namespace tp_data_features
{

//##################################################################################################
struct SimpleMatch
{
  size_t indexA{0};
  size_t indexB{0};
  glm::vec2 coord2DA{0.0f, 0.0f};
  glm::vec2 coord2DB{0.0f, 0.0f};
  glm::vec3 coord3D{0.0f, 0.0f, 0.0f};
};

//##################################################################################################
class SimpleMatchesMember : public MatchesMember
{
public:
  //################################################################################################
  SimpleMatchesMember(const std::string& name=std::string());

  //################################################################################################
  ~SimpleMatchesMember() override;

  //################################################################################################
  static SimpleMatchesMember* fromData(std::string& error, const std::string& data);

  //################################################################################################
  std::string toData() const;

  //################################################################################################
  void copyData(const SimpleMatchesMember& other);

  static const std::string extension;
  std::vector<SimpleMatch> data;
};

//##################################################################################################
using SimpleMatchesMemberFactory = tp_data::MultiDataMemberFactoryTemplate<SimpleMatchesMember, matchesSID>;

}

#endif
