#include <osdialog.h>
#include <iostream>

int main(int argc, char *argv[])
{

  std::cout << "test\n";

  osdialog_color color0 = {200, 200, 100};
  std::cout << "cor antes: "
            << (int)*((uint8_t *)(&color0) + sizeof(uint8_t) * 0) << ", "
            << (int)*((uint8_t *)(&color0) + sizeof(uint8_t) * 1) << ", "
            << (int)*((uint8_t *)(&color0) + sizeof(uint8_t) * 2) << ", "
            << (int)*((uint8_t *)(&color0) + sizeof(uint8_t) * 3)
            << '\n';
  osdialog_color_picker(&color0, 0);
  std::cout << "cor depois: "
            << (int)*((uint8_t *)(&color0) + sizeof(uint8_t) * 0) << ", "
            << (int)*((uint8_t *)(&color0) + sizeof(uint8_t) * 1) << ", "
            << (int)*((uint8_t *)(&color0) + sizeof(uint8_t) * 2) << ", "
            << (int)*((uint8_t *)(&color0) + sizeof(uint8_t) * 3)
            << '\n';

  char *path = osdialog_file(OSDIALOG_OPEN, NULL, NULL, NULL);

  std::cout << "path: " << path << '\n';

  return 0;
}
