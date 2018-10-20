#include <iostream>

#include <boost/program_options.hpp>

namespace po = boost::program_options;

int main(int argc, char **argv) {
  po::options_description desc("Allowed options", 200);
  desc.add_options()
      ("dev,d", "dev mode.\n");

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);

  if (vm.count("dev")) {

    return 0;
  }

  return 0;
}