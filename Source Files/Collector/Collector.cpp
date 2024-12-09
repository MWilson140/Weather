#include "Collector.h"

void Collector::CollData(const NDC & ndc)
{
    Destination->FillData(ndc);
}
