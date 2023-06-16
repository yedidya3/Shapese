#pragma once
#include "Group.h"
#include <memory>
#include <string>

namespace experis
{


std::unique_ptr<Group> LoadPainting(const std::string& a_nameFile);

void WritePainting(const std::string& a_nameFile, const Group& a_painting);
}