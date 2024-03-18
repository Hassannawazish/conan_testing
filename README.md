## Setting up Environment 

    For demo purposes, I am using the library named as PugiXML which is normally used to read the xml files in C/C++ .

    I am using Ubuntu 20.04, with gcc version 5.5 and cmake version 3.20.0 .
    Fisrt step is to install python Python 3.6.13 and Conan using pip. (Conan Version should be Conan version 1.52.0).

    Make sure all versions are correct. You can use Anaconda and create a conda environment for your ease.

    Initially a conanfile.txt is used to create the conan package of any 3rd party repository, just need to setup conanfile functions according to build type, os type, packeges files names and versions like here we did for pugixml 1.14. For more clarity or in case of errors you can see the CMakelists.txt code for the library you want to package like pugixml in this case.

    Only conanfile.py is required for creation. Need to other files to keep the things simple.  

## Creation of Conan Package
    local Creation

    $ cd create
    $ conan new pugixml/1.14                             (this command will create a template conanfile.txt you have to replace it with the file     
                                                        provided by me and you can compare both files to see the contents I have added to create package for 3rd party library) (it can replace the file is already exists to take care)
    $ conan create . user/testing
    $ conan search pugixml/1.14@user/testing
    $ conan create . user/testing -s build_type=Debug
    $ conan search pugixml/1.14@user/testing

    Setup Remote repository on jfrog Artifacts / Nexus to upload the conan package/recipe of pugixml onto the cloud.
    Create an account on jfrog(can be free trail). Create a repository by selecting conan package and copy the repository link.(should be like https://hassannaw.jfrog.io/artifactory/api/conan/myconanrepo ) 

    $ conan remote add artifactory https://hassannaw.jfrog.io/artifactory/api/conan/myconanrepo
    $ conan remote list
        (have to replace artifactory name here by your artifactory)
    $ conan upload "pugixml*" -r artifactory
    $ conan search "*" -r=artifactory
    $ conan search pugixml/1.14@user/testing -r=artifactory                  (After this conan have only uploaded the package recipe for pugixml)
    $ conan upload "pugixml*" -r artifactory --all --confirm
    $ conan search "*" -r=artifactory

    By using these commands you will generate the package and upload is to repository and check the remote existance by searching commands as provided above. 


## Consumption of Conan Package

    For consumption of conan package named as pugixml/1.14@user/testing first of all conanfile.txt is required.
    we can use and run in c++ code by using the following commands.

    $   cd consume/
    $   conan install .. -r=pugixml-hassan-conan
    $   cmake .. -DCMAKE_BUILD_TYPE=Release
    $   make -j4
    $   cd bin/
    $   ./xml_reader

    It will run the executable which it utilizing the conan package.