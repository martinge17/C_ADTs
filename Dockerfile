FROM alpine:latest

RUN apk update && apk add build-base git 

RUN git clone https://github.com/martinge17/C_ADTs.git




