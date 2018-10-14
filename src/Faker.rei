let nullable: option('a) => Js.Nullable.t('a);
type nullable('a);
let fake: string => Belt.Result.t(string, Js.Exn.t);
