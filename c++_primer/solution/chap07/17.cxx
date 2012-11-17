#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cctype>
using namespace std;

const char * const program_name = "comline";
const char * const program_version = "version 7.15";

inline void usage(int exit_value = 0)
{
    // print a formatted usage message
    // and exits using the EXIT_VALUE ...

    cerr << "usage:\n"
         << program_name << " "
         << "[-d] [-n] [-v] [-t]\n\t"
         // change begins
         << "[-b bufsize] [-o output_file] [-l limit] \n\t"
         // change ends
         << "file_name\n\t[file_name [file_name [...]]]\n\n"
         << "where [] indicates optional option:\n\n\t"
         << "-h: help.\n\t\t"
         << "generate this message and exits\n\n\t"
         << "-v: version.\n\t\t"
         << "prints version information and exits\n\n\t"
         << "-d: debug.\n\t\tturns debugging on \n\n\t"
         << "-t: timer.\n\t\tturns timer on\n\n\t"
         // change begins
         << "-b bufsize\n\t\t"
         << "bufsize must be a non-negative integer\n\n\t"
         // change ends
         << "-l limit\n\t\t"
         << "limit must be a non-negative integer\n\n\t"
         << "-o output_file\n\t\t"
         << "output_file within which to write out results\n\t\t"
         << "by default, results written to standard output.\n\n"
         << "file_name\n\t\t"
         << "the name of the actual file to process\n\t\t"
         << "at least one file is required --\n\t\t"
         << "any number may be specified\n\n"
         << "examples:\n\t\t"
         << "$command chapter7.doc\n\t\t"
         << "$command -d -l 1024 -o test_7_8 "
         << "chapter7.doc chapter8.doc\n\n";

     exit(exit_value);
}

int main(int argc, char *argv[])
{
    bool debug_on = false;
    bool ofile_on = false;
    bool limit_on = false;
    int  limit = -1;

    // change begins
    bool timer_on = false;
    bool bufsize_on = false;
    int bufsize = -1;
    // change ends

    string ofile;
    vector<string> file_name;

    cout << "illustration of handling command line arguments:\n"
         << "argc: " << argc << endl;

    for (int ix = 1; ix < argc; ++ix)
    {
        cout << "argv[" << ix << "]: "
             << argv[ix] << endl;

        char *pchar = argv[ix];
        switch (pchar[0])
        {
            case '-':
                cout << "case \'-\' found\n";
                switch (pchar[1])
                {
                    case 'd':
                        cout << "-d found: "
                             << "debugging turned on\n";
                        debug_on = true;
                        break;

                    // change begins
                    case 't':
                        cout << "-t found: "
                             << "timer turns on" << endl;
                        timer_on = true;
                        break;
                    // change ends
                    case 'v':
                        cout << "-v found: "
                             << "version info displayed" << endl;
                        cout << program_name 
                             << "::"
                             << program_version
                             << endl;
                        return 0;
                    case 'h':
                        cout << "-h found: "
                             << "help information\n";
                        usage();
                        
                    case 'o':
                        cout << "-o found: "
                             << "output file\n";
                        if (pchar[2] == '\0')
                            ofile_on = true;
                        else 
                        {
                            cout << "argument immediately following: "
                                 << pchar + 2 << endl;
                            ofile = pchar + 2;
                        }
                        break;

                    case 'l':
                        cout << "-l found: "
                             << "resouce limit\n";
                        if (pchar[2] == '\0')
                            limit_on = true;
                        else
                        {
                            cout << "argument immediately following: "
                                 << pchar + 2 << endl;
                            limit = atoi(pchar + 2);
                            if (limit < 0)
                            {
                                cerr << program_name
                                     << " : error: "
                                     << "negative value for limit.\n\n";
                                usage(-2);
                            }
                        }
                        break;

                    // change begins
                    case 'b':
                        cout << "-b found: "
                             << "bufsize\n";
                        if (pchar[2] == '\0')
                            bufsize_on = true;
                        else 
                        {
                            cout << "augument immediately following: "
                                 << pchar + 2 << endl;
                            bufsize = atoi(pchar + 2);
                            if (bufsize < 0)
                            {
                                cerr << program_name
                                     << " : error : "
                                     << "negative value for bufsize.\n\n";
                                usage(-4);
                            }
                        }
                        break;
                    // change ends

                    case '\0':
                        cerr << program_name
                             << " : error : "
                             << "space following hyhpen not allowed.\n\n";
                        usage(-5);

                    default:
                        cerr << program_name
                             << " : error : "
                             << "unrecongnized option: -"
                             << pchar << "\n\n";
                        usage(-1);
                        break;

                }
                break;

            default:
                cout << "default non-hypen argument: "
                     << pchar << endl;

                if (ofile_on) 
                {
                    ofile_on = false;
                    ofile = pchar;
                }
                else if (limit_on)
                {
                    limit_on = false;
                    limit = atoi(pchar);
                    if (limit < 0)
                    {
                        cerr << program_name 
                             << " : error : "
                             << "negative value for limit.\n\n";
                        usage(-2);
                    }
                }
                else if (bufsize_on)
                {
                    bufsize_on = false;
                    bufsize = atoi(pchar);
                    if (bufsize < 0)
                    {
                        cerr << program_name 
                             << " : error : "
                             << "negative value for bufsize.\n\n";
                        usage(-4);

                    }
                }
                else
                {
                    file_name.push_back(string(pchar));
                }
                break;
        }
    }

    if (file_name.empty())
    {
        cerr << program_name << " : error : "
             << "no file specified for processing.\n\n";
        usage(-3);
    }

    if (limit != -1)
    {
        cout << "User-specified limit: "
             << limit << endl;
    }

    if (bufsize != -1)
    {
        cout << "User-specified bufsize: "
             << bufsize << endl;
    }

    if (!ofile.empty())
    {
        cout << "User-specified output file: "
             << ofile << endl;
    }

    cout << (file_name.size() == 1 ? "File " : "Files ")
         << "to be processed are the following:\n";

    for (vector<string>::size_type inx = 0; inx < file_name.size(); ++inx)
    {
        cout << "\t" << file_name.at(inx) << endl;
    }

    return 0;
}


