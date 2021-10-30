# base image
#!/bin/bash

FROM ubuntu:latest AS base

FROM base AS dependencies
# install cmake, gcc, g++, boost, and git
RUN apt-get update &&\
    apt-get install -yq cmake gcc g++ &&\
    apt-get install -yq git &&\
    apt-get install -yq libcurl4-openssl-dev &&\
    apt-get install -yq libboost-all-dev &&\
    apt-get install -yq libssl-dev &&\
    mkdir EW_LibraryHub

WORKDIR /EW_LibraryHub/

RUN mkdir include
RUN git clone --branch 1.6.2 https://github.com/libcpr/cpr &&\
    cd cpr && mkdir build && cd build &&\
    cmake .. -DBUILD_SHARED_LIBS=False &&\
    make

RUN git clone --branch v0.3 https://github.com/CrowCpp/crow &&\
    cp -r crow/include/. include &&\
    mkdir build

FROM dependencies AS depdev
CMD [ "/bin/bash" ]

# copy all of the source files to the image
FROM dependencies AS builder
COPY ./ ./
WORKDIR build
RUN cmake .. &&\
    make 

FROM builder AS builderdev
CMD [ "/bin/bash" ]

FROM builder AS production
ENTRYPOINT ["src/fileServer"]
