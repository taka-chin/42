FROM alpine:latest

WORKDIR /app

RUN apk update && \
    apk add --upgrade apk-tools && \
    apk upgrade --available && \
    apk add bash clang-extra-tools python3 py3-pip py3-virtualenv && \
    clang-format --version

COPY . .

CMD ["./formatter.sh"]
