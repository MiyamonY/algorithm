;;; File:  main.scm
;; Author: ymiyamoto
;;
;; Created on Sun Oct 13 22:14:33 2019
;;
(define-syntax read-number
  (syntax-rules ()
    ((_ nums)
     (define-values nums
       (apply values (map string->number (string-split (read-line) #\space)))))))

(define-syntax read-numbers
  (syntax-rules ()
    ((_ as)
     (define as (map string->number (string-split (read-line) #\space))))
    ((_ as n)
     (define as (map (lambda (_) (map string->number (string-split (read-line) #\space))) (iota n))))))

(define-syntax prlist
  (syntax-rules ()
    ((_ lis)
     (print (string-join (map number->string lis) " ")))))

(define-syntax 1+ (syntax-rules () ((_ x) (+ x 1))))

(define-syntax 1- (syntax-rules () ((_ x) (- x 1))))

(define MOD 1000000007)

(define (binary-search vec pred)
  (let loop ((left -1)
	     (right (vector-length vec)))
    (let1 mid (div (+ left right) 2)
	  (cond ((>= left (1- right)) right)
		((pred (vector-ref vec mid)) (loop left mid))
		(else (loop mid right))))))

(define (main args)
  (use gauche.test)

  (test-start "binary search")
  (test-section "vector is null")
  (test "vec is null" 0 (lambda () (binary-search #() (lambda (x) (< 0 x)))))

  (test-section "vector is single")
  (test "value is above" 1 (lambda () (binary-search #(2) (lambda (x) (< 3 x)))))
  (test "value is below" 0 (lambda () (binary-search #(2) (lambda (x) (< 0 x)))))
  (test "value is equal" 0 (lambda () (binary-search #(2) (lambda (x) (<= 0 2)))))

  (test-section "vector is multiple")
  (test "value is below" 0 (lambda () (binary-search #(2 4 6) (lambda (x) (< 0 x)))))
  (test "value is above" 3 (lambda () (binary-search #(2 4 6) (lambda (x) (< 6 x)))))
  (test "value is mid1" 0 (lambda () (binary-search #(2 4 6) (lambda (x) (<= 2 x)))))
  (test "value is mid2" 1 (lambda () (binary-search #(2 4 6) (lambda (x) (<= 3 x)))))
  (test "value is mid2" 1 (lambda () (binary-search #(2 4 6) (lambda (x) (<= 4 x)))))
  (test-end))
