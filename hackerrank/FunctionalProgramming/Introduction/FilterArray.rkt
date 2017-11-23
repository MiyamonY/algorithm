;;;
;; File:  FilterArray.rkt
;; Author: ymiyamoto
;;
;; Created on Sat Oct 14 01:39:01 2017
;;
#lang racket

(define n (string->number (read-line)))

(define (read-lines)
  (let ((line (read-line)))
    (if (eq? line eof)
        (list)
        (cons (string->number line) (read-lines)))))

(define (filter proc xs)
  (if (null? xs)
      (list)
      (let ((val (first xs)))
        (if (proc val)
            (cons val (filter proc (rest xs)))
            (filter proc (rest xs))))))

(for ((i (filter
          (lambda (x) (< x n))
          (read-lines))))
  (displayln i))
