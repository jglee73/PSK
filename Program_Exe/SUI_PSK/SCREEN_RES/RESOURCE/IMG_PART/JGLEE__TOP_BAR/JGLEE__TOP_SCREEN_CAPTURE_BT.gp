#BITMAP
{
JGLEE__TOP_SCREEN SHOT_INACTIVE.bmp
0 0 22 22
0
}
#DYNAMIC
{
IF_AND: (dCH1 != dSts1)
VIS 1
}
#BITMAP
{
JGLEE__TOP_SCREEN SHOT_ON.bmp
0 0 22 22
0
}
#DYNAMIC
{
IF_OR: (dCH1 == dSts1)
VIS 1
}
