# base image
FROM ubuntu:latest

# install cmake, gcc, g++, boost, and git
RUN apt-get update
RUN apt-get install -yq cmake gcc g++

# make a directory we'll use to build
RUN mkdir build

# copy all of the source files to the image
COPY ./ /

# build the app
WORKDIR build
RUN cmake ..
RUN make 

# run the app!
ENTRYPOINT ["src/fileServer"]
