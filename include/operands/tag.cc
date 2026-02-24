#include "tag.h"
#include "../RAM/ram.h"

int Tag::getOperand(const Ram& ram) const { return ram.getProgramMemory().translateAddress(tag_); }