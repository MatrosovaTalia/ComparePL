FROM picroc/lang_driver:0.4

# RUN apt-get update

# RUN curl -sL https://deb.nodesource.com/setup_10.x | bash -
# RUN apt install -y nodejs
# RUN apt-get install -y clang libicu-dev wget

# RUN wget https://swift.org/builds/swift-5.1.4-release/ubuntu1804/swift-5.1.4-RELEASE/swift-5.1.4-RELEASE-ubuntu18.04.tar.gz
# RUN mkdir ~/swift
# RUN tar -xvzf swift-5.1.4-RELEASE-ubuntu18.04.tar.gz -C ~/swift
# ENV PATH=$PATH:~/swift/swift-5.1.4-RELEASE-ubuntu18.04/usr/bin

# RUN ~/swift/swift-5.1.4-RELEASE-ubuntu18.04/usr/bin/swift --version

# RUN apt-get install time -y

ADD . /app
WORKDIR /app
ENTRYPOINT [ "bash" , "run_profiler.sh" , "run" ]