#BITMAP
{
JGLEE__BOTTOM_UTILITY_DISABLE.bmp
0 0 124 73
0
}
#DYNAMIC
{
IF_OR: (dCH != dSts)
VIS 1
}
#BITMAP
{
JGLEE__BOTTOM_UTILITY_ACTIVE.bmp
0 0 124 73
0
}
#DYNAMIC
{
IF_OR: (dCH == dSts)
VIS 1
}