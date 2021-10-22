# base image
#!/bin/bash

FROM ubuntu:latest AS base

FROM base AS builder
# install cmake, gcc, g++, boost, and git
RUN apt-get update
RUN apt-get install -yq cmake gcc g++
RUN apt-get install -yq git
RUN apt-get install -yq libcurl4-openssl-dev

RUN mkdir EW_LibraryHub
WORKDIR /EW_LibraryHub/

RUN git clone --branch v0.3 https://github.com/CrowCpp/crow
RUN cp -r crow/include include
# make a directory we'll use to build
RUN mkdir build

# copy all of the source files to the image
COPY ./ ./

# build the app
WORKDIR build
RUN cmake ..
RUN make 

FROM builder AS builderdev
CMD [ "/bin/bash" ]

FROM base AS finalimage
COPY --from=builder /EW_LibraryHub/build/src/fileServer /

FROM finalimage AS finaldev
CMD [ "/bin/bash" ]

FROM finalimage AS production
ENTRYPOINT ["/fileServer"]
