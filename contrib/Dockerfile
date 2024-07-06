FROM amd64/ubuntu:20.04 AS base

#If you found this docker image helpful please donate DOGPUS to the maintainer
LABEL maintainer="RV9zdNeUTQUToZUcRp9uNF8gwH5LzDFtan"

EXPOSE 6068/tcp
EXPOSE 6069/tcp

ENV DEBIAN_FRONTEND=noninteractive

#Install runtime dependencies
RUN apt-get update && \
	apt-get install -y --no-install-recommends \
	bash wget net-tools libminiupnpc17 \
	libevent-2.1 libevent-pthreads-2.1 \
	libboost-system1.71 libboost-filesystem1.71 libboost-chrono1.71 \
	libboost-program-options1.71 libboost-thread1.71 \
	libzmq5 && \
	apt-get clean

FROM base AS build

#Install build dependencies
RUN apt-get update && \
	apt-get install -y --no-install-recommends \
	bash net-tools build-essential libtool autotools-dev automake \
	pkg-config libssl-dev libevent-dev bsdmainutils python3 \
	libboost-system1.71-dev libboost-filesystem1.71-dev libboost-chrono1.71-dev \
	libboost-program-options1.71-dev libboost-test1.71-dev libboost-thread1.71-dev \
	libzmq3-dev libminiupnpc-dev && \
	apt-get clean

#Copy source dir
COPY . /home/dogpu/build/Dogegpu/
WORKDIR /home/dogpu/build/Dogegpu

#build db4 from source
WORKDIR /home/dogpu/build/Dogegpu/contrib
RUN ./install_db4.sh ../../

# build Dogpucore
WORKDIR /home/dogpu/build/Dogegpu
RUN ./autogen.sh && ./configure --disable-tests BDB_LIBS="-L/home/dogpu/build/db4/lib -ldb_cxx-4.8" BDB_CFLAGS="-I/home/dogpu/build/db4/include" --with-gui=no  && make -j4

FROM base AS final

#Add our service account user
RUN useradd -ms /bin/bash dogpu && \
	mkdir /var/lib/dogpu && \
	chown dogpu:dogpu /var/lib/dogpu && \
	ln -s /var/lib/dogpu /home/dogpu/.dogpu && \
	chown -h dogpu:dogpu /home/dogpu/.dogpu

VOLUME /var/lib/dogpu

#Copy the compiled binaries from the build
COPY --from=build /home/dogpu/build/Dogegpu/src/dogpud /usr/local/bin/dogpud
COPY --from=build /home/dogpu/build/Dogegpu/src/dogpu-cli /usr/local/bin/dogpu-cli

WORKDIR /home/dogpu
USER dogpu

CMD /usr/local/bin/dogpud -datadir=/var/lib/dogpu -printtoconsole -onlynet=ipv4
