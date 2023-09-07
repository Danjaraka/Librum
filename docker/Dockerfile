FROM ubuntu:20.04

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive

# # Install necessary packages
RUN apt-get update -y && \
    apt-get install -y \
    git \
    make \
    unzip \
    wget \
    g++ \
    make \
    python3 \
    python3-pip \
    && rm -rf /var/lib/apt/lists/*

RUN apt-get update \
  && apt-get -y install build-essential \
  && apt-get install -y wget \
  && rm -rf /var/lib/apt/lists/* \
  && wget https://github.com/Kitware/CMake/releases/download/v3.24.1/cmake-3.24.1-Linux-x86_64.sh \
      -q -O /tmp/cmake-install.sh \
      && chmod u+x /tmp/cmake-install.sh \
      && mkdir /opt/cmake-3.24.1 \
      && /tmp/cmake-install.sh --skip-license --prefix=/opt/cmake-3.24.1 \
      && rm /tmp/cmake-install.sh \
      && ln -s /opt/cmake-3.24.1/bin/* /usr/local/bin

RUN pip3 install pipenv
COPY Qt /Qt
WORKDIR /Qt
RUN pipenv install
RUN pipenv run ./qt-downloader linux desktop 6.5.2 gcc_64 --opensource

COPY ./ /Librum
WORKDIR /Librum
# # Create the build folder and step into it
RUN mkdir build-Release && cd build-Release

# # Run CMake with the appropriate parameters
RUN cmake -DCMAKE_INSTALL_PREFIX=/usr \
    -DCMAKE_BUILD_TYPE=Release \
    -DBUILD_TESTS=Off \
    -DCMAKE_PREFIX_PATH=/Qt/6.5.2/gcc_64 \
    ..

# Build the project
# RUN cmake --build . -j $(nproc)

# # Install Librum
# RUN cmake --install .

# Expose any necessary ports if your application requires it
# EXPOSE 80

# Specify the command to run your application, if needed
# CMD ["/usr/bin/your-app"]

# Clean up the image
WORKDIR /
# RUN rm -rf /Librum

# Clean up the package manager caches
# RUN apt-get clean

# Optionally, remove package manager
# RUN rm -rf /var/lib/apt/lists/* /var/cache/apt/archives/*

# Set any environment variables your application may require
# ENV MY_VAR=example_value

# Specify any additional configurations, volumes, or metadata here
