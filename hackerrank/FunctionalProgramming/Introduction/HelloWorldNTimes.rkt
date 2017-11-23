;;;
;; File:  HelloWorldNTimes.rkt
;; Author: ymiyamoto
;;
;; Created on Sat Oct 14 00:18:20 2017
;;
#lang racket

(define n (string->number (read-line)))

(define (display-n-times n)
  (if (= n 0)
      (void)
      (begin
        (displayln "Hello World")
        (display-n-times (- n 1)))))

(display-n-times n)
