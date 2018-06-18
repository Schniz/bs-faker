open Jest;
open Expect;
open! Expect.Operators;

describe("Faker.Name", () => {
  describe(".findName", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Faker.Name.findName())) === "string"
    );
    test("accepts firstName", () =>
      expect(Faker.Name.findName(~firstName="Gal", ())) |> toMatchRe(Js.Re.fromString("^Gal "))
    );
    test("accepts lastName", () =>
      expect(Faker.Name.findName(~lastName="Hagever", ())) |> toMatchRe(Js.Re.fromString(" Hagever$"))
    );
  });

  test(".firstName", () =>
    expect(Js.typeof(Faker.Name.firstName())) === "string"
  );
  test(".lastName", () =>
    expect(Js.typeof(Faker.Name.lastName())) === "string"
  );
  test(".prefix", () =>
    expect(Js.typeof(Faker.Name.prefix())) === "string"
  );
  test(".suffix", () =>
    expect(Js.typeof(Faker.Name.suffix())) === "string"
  );
  test(".title", () =>
    expect(Js.typeof(Faker.Name.title())) === "string"
  );
  test(".jobArea", () =>
    expect(Js.typeof(Faker.Name.jobArea())) === "string"
  );
  test(".jobType", () =>
    expect(Js.typeof(Faker.Name.jobType())) === "string"
  );
});
