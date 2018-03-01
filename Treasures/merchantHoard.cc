#include "merchantHoard.h"

MerchantHoard::MerchantHoard(int x, int y) : Treasure{x, y, 6} {}

MerchantHoard::~MerchantHoard() { if(component) delete component; }
