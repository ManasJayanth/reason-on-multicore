print_endline("hey there");

let num_domains =
  try(int_of_string(Sys.argv[1])) {
  | _ => 1
  };
let n =
  try(int_of_string(Sys.argv[2])) {
  | _ => 40
  };

module T = Domainslib.Task;

let _ = {
  let p = T.setup_pool(~num_domains=num_domains - 1);
  let sum =
    T.parallel_for_reduce(
      p,
      (+),
      0,
      ~chunk_size=n / (4 * num_domains),
      ~start=0,
      ~finish=n - 1,
      ~body=_i =>
      1
    );

  T.teardown_pool(p);
  Printf.printf("Sum is %d\n", sum);
};
