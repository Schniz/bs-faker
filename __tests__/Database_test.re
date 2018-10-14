open Jest;
open Expect;
open! Expect.Operators;

describe("Faker.Database", () => {
  test(".column", () =>
    expect(Js.typeof(Database.column())) === "string"
  );
  test(".type_", () =>
    expect(Js.typeof(Database.type_())) === "string"
  );
  test(".collation", () =>
    expect(Js.typeof(Database.collation())) === "string"
  );
  test(".engine", () =>
    expect(Js.typeof(Database.engine())) === "string"
  );
});
