## Setting up Environment 

    For demo purposes, I am using the library named as PugiXML which is normally used to read the xml files in C/C++ .

    I am using Ubuntu 20.04, with gcc version 5.5 and cmake version 3.20.0 .
    Fisrt step is to install python Python 3.6.13 and Conan using pip. (Conan Version should be Conan version 1.52.0).

    Make sure all versions are correct. You can use Anaconda and create a conda environment for your ease.

## Creation of Conan Package
    local Creation

    $ cd create
    $ conan new pugixml/1.11
    $ create . user/testing
    $ conan search pugixml/1.11@user/testing
    $ conan create . user/testing -s build_type=Debug
    $ conan search pugixml/1.11@user/testing

    Setup Remote repository on jfrog Artifacts / Nexus to upload the conan package/recipe of pugixml onto the cloud.
    Create an account on jfrog(can be free trail). Create a repository by selecting conan package and copy the repository link.(should be like https://hassannaw.jfrog.io/artifactory/api/conan/myconanrepo ) 

    $ conan remote add artifactory https://hassannaw.jfrog.io/artifactory/api/conan/myconanrepo
    $ conan remote list
    $ conan upload "pugixml*" -r artifactory
    $ conan search "*" -r=artifactory
    $ conan search pugixml/1.11@user/testing -r=artifactory                  (After this conan have only uploaded the package recipe for pugixml)
    $ conan upload "pugixml*" -r artifactory --all --confirm
    $ conan search "*" -r=artifactory
