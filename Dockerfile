FROM runar0/docker-gcc-nasm-cmake

COPY /boot-loader /boot-loader
COPY /kernel32 /kernel32
COPY /kernel64 /kernel64
COPY /utility /utility
COPY /Makefile /Makefile
RUN mkdir out

VOLUME /out

CMD ["make"]