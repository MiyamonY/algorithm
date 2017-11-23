;;;
;; File:  FilterPositionsInAList.rkt
;; Author: ymiyamoto
;;
;; Created on Sat Oct 14 01:48:45 2017
;;
#lang racket

(define n (string->number (read-line)))

(define (read-lines)
  (let ((line (read-line)))
    (if (eq? line eof)
        (list)
        (cons (string->number line) (read-lines)))))

(define (ifilter proc ls)
  (define (iter i ls)
    (if (null? ls)
        (list)
        (if (proc i (first ls))
            (cons (first ls) (iter (+ i 1) (rest ls)))
            (iter (+ i 1) (rest ls)))))
  (iter 0 ls))

(for ((i (ifilter
          (lambda (n x) (even? n))
          (read-lines))))
  (displayln i))
