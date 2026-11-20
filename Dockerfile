
FROM gcc:latest

WORKDIR /app

COPY memory.c procinfo.c ./

RUN gcc memory.c -o memory
RUN gcc procinfo.c -o procinfo

CMD ["./memory"]
