# base image
#!/bin/bash

FROM ubuntu:latest AS base

FROM base AS builder
# install cmake, gcc, g++, boost, and git
RUN apt-get update &&\
    apt-get install -yq cmake gcc g++ &&\
    apt-get install -yq git &&\
    apt-get install -yq libcurl4-openssl-dev &&\
    apt-get install -yq libboost-all-dev &&\
    apt-get install -yq libssl-dev &&\
    mkdir EW_LibraryHub

WORKDIR /EW_LibraryHub/

RUN git clone --branch v0.3 https://github.com/CrowCpp/crow &&\
    cp -r crow/include include &&\
    mkdir build

FROM builder AS builddev
CMD [ "/bin/bash" ]

# copy all of the source files to the image
FROM builder AS finalbuild
COPY ./ ./

# build the app
WORKDIR build
RUN cmake .. &&\
    make 

FROM finalbuild AS builderdev
CMD [ "/bin/bash" ]

FROM finalbuild AS production
ENTRYPOINT ["src/fileServer"]
