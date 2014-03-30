#include <string>
#include <vector>
#include <iostream>

#include <getopt/getopt.h>

int main(int argc, char** argv)
{
    using getopt::Option;
    using getopt::Present;
    using getopt::PosOption;

    getopt::Options     ops(argc, argv);

    std::string                     name    = "Pepper";
    int                             age     = 7;
    std::vector<std::string>        coordinates;
    ops
        >> Option(      "name",     name,           "name of the person")
        >> Option('a',  "age",      age,            "age of the person")
        >> Option('c',  "coord",    coordinates,    "coordinates")
    ;
    bool negate = ops >> Present('n', "negate", "negate the function");

    std::string infilename;
    if ( (ops >> Present('h', "help", "show help message")) ||
        !(ops >> PosOption(infilename)))
    {
        std::cout << "Usage: " << argv[0] << " [options] INFILE\n";
        std::cout << "Sample options program\n\n";
        std::cout << ops << std::endl;
        return 1;
    }

    // Alternative form
    //if ( (ops >> Present('h', "help", "show help message") ||
    //    !(ops >> PosOption(infilename, "INFILE")))
    //{
    //    std::cout << ops.usage("Sample options program");
    //    return 1;
    //}

    std::cout << "Infilename: " << infilename << std::endl;
    std::cout << "Name:       " << name       << std::endl;
    std::cout << "Age:        " << age        << std::endl;
    std::cout << "Negate:     " << negate     << std::endl;
    std::cout << "Coorindates:" << std::endl;
    for (unsigned i = 0; i < coordinates.size(); ++i)
        std::cout << "  " << coordinates[i] << std::endl;
}
