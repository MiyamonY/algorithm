;;; File:  main.scm
;; Author: ymiyamoto
;;
;; Created on Sat Sep 28 23:10:50 2019
;;
(define MOD 1000000007)

(define (mod+ x y)
  (modulo (+ x y) MOD))

(define (mod* x y)
  (modulo (* x y) MOD))

(define (make-comb num)
  (define fact-dp (make-vector num -1))
  (define inv-fact-dp (make-vector num -1))
  (define (fact n) (vector-ref fact-dp n))
  (define (inv-fact n) (vector-ref inv-fact-dp n))

  (vector-set! fact-dp 0 1)
  (vector-set! inv-fact-dp 0 1)
  (let loop ((i 1))
    (when (< i num)
      (vector-set! fact-dp i (mod* i (fact (- i 1))))
      (vector-set! inv-fact-dp i (expt-mod (fact i) (- MOD 2) MOD))
      (loop (+ i 1))))

  (lambda (n k)
    (define factn (fact n))
    (define powk (inv-fact k))
    (define pownk (inv-fact (- n k)))
    (mod* (mod* factn powk) pownk)))
