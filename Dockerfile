FROM gcc:latest

WORKDIR /app

COPY memory.c .

RUN gcc memory.c -o memory

CMD ["./memory"]
