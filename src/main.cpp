#include <iostream>
#include <cstdio>
#include "servercheck.hpp"
#include "updaterConfig.hpp"
#include "cli.hpp"

using namespace std;

int main( int argc, char ** argv ) {
  GPEUP::CLI cli;
  GPEUP::ServerCheck sc;

  cli.version();
  cli.help(*argv);
  cli.prompt();
  //sc.check();
  return 0;
}
