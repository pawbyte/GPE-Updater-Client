#include <iostream>
#include <cstdio>
#include "updater.hpp"
#include "updaterConfig.hpp"
#include "cli.hpp"

using namespace std;

int main( int argc, char ** argv ) {
  CLI test;
  test.version();
  test.help(*argv);
  return 0;
}
