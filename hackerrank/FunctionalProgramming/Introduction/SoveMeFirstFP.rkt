#lang racket

(define a (string->number (read-line)))
(define b (string->number (read-line)))
(displayln (+ a b))
