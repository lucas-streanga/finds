#include<filesystem>
#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
#include<stdio.h>

#if DEBUG == 1
#define LOG(x) std::clog << x << '\n'
#else
#define LOG(x)
#endif

#define MAX_RETRY 20

namespace fs = std::filesystem;

bool g_found;
unsigned int g_tries;

unsigned long long find_recursive(const fs::path& path, const std::string & s)
{
    g_tries++;
    if(g_tries > MAX_RETRY)
    {
      printf("Max retries (%u) reached at directory %s\n", MAX_RETRY, path.c_str());
      return 0;
    }
    fs::path pa;
    fs::path cur_directory;
    unsigned long long occurances = 0;
    try
    {
      for(const auto& p: fs::recursive_directory_iterator(path, fs::directory_options::skip_permission_denied))
      {
          pa = p.path();
          LOG("Scanning " << pa);

          try
          {
            if(fs::is_directory(p))
            {
              cur_directory = pa;
              continue;
            }

            if (fs::exists(p) && fs::is_regular_file(p))
            {
              //Try to find the string
              //if((fs::status(p).permissions() & fs::perms::owner_exec) != fs::perms::none)
              //  continue;
              std::ifstream file(pa.c_str());

              if(file.is_open())
              {
                unsigned long long i = 1;
                std::string line;
                while(getline(file, line))
                {
                  if(line.find(s) != std::string::npos)
                  {
                    printf("Found \"%s\" at %s line %llu\n", s.c_str(), pa.c_str(),  i);
                    occurances++;
                    g_found = true;
                  }

                  i++;
                }
                file.close();
              }
            }
            else
            {
              LOG("Skipped " << pa << " (either a directory or unopenable)");
            }
        }
        catch(fs::filesystem_error &e)
        {
            LOG("Skipped " << pa << " (either a directory or unopenable)");
        }
      }
    }
    catch(fs::filesystem_error& e)
    {
      std::cout << "Unable to access file or path " << pa <<": " << e.what() << "\n";
      //try again from the current directory
      occurances += find_recursive(cur_directory, s);
    }
    catch(std::bad_alloc&)
    {
      std::cout << "Allocation error. " << "\n";
      return 0;
    }
    return occurances;
}

int main(int argc, char ** argv)
{
  g_found = false;
  g_tries = 0;

  if(argc < 3)
  {
    printf("No path or file specified...\n");
    return 0;
  }

  unsigned long long occurances = 0;

  for(int j = 2; j < argc; j++)
  {
    fs::path p(argv[j]);

    if(fs::is_directory(p))
    {
      occurances += find_recursive(p, argv[1]);
    }
    else
    {
      std::ifstream file(argv[2]);

      if(file.is_open())
      {
        unsigned long long i = 1;
        std::string line;
        while(getline(file, line))
        {
          if(line.find(argv[1]) != std::string::npos)
          {
            printf("Found \"%s\" at %s line %llu\n", argv[1], argv[j],  i);
            g_found = true;
          }
          i++;
        }
        file.close();
      }
      else
      {
        printf("Unable to open file %s.\n", argv[j]);
      }
    }
  }

  if(!g_found)
    std::cout << "String not found!\n";

  if(occurances)
    printf("Found %llu occurances.\n",  occurances);

  return 0;
}
