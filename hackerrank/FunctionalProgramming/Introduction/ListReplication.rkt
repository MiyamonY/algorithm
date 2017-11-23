;;;
;; File:  ListReplication.rkt
;; Author: ymiyamoto
;;
;; Created on Sat Oct 14 01:22:19 2017
;;
#lang racket

(define n (string->number (read-line)))

(define (read-lines)
  (let ((val (read-line)))
    (if (eq? val eof)
      (list)
      (cons (string->number val) (read-lines)))))

(define (displayln-n s times)
  (if (= times 0)
      (void)
      (begin
        (displayln s)
        (displayln-n s (- times 1)))))

(for ((i (read-lines)))
  (displayln-n i n))
