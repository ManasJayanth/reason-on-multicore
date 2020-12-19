open Lwt.Syntax;

Lwt_preemptive.init(0, 4, print_endline);

let rec fib = fun
| 0 => 0
| 1 => 1
| n => {  fib(n - 1) + fib (n - 2); }

let thread = n => {
  fib(n)
};

let data = [45, 45, 45, 45];

List.map(n => {
  let+ v = Lwt_preemptive.detach(thread, n);
  print_int(v);
  print_newline();
}, data)
|> Lwt.join
|> Lwt_main.run

/* List.iter(n => { */
/*   let v = thread(n); */
/*   print_int(v); */
/*   print_newline(); */
/* }, data); */

