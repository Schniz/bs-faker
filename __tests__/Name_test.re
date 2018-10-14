open Jest;
open Expect;
open! Expect.Operators;

describe("Faker.Name", () => {
  describe(".findName", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Name.findName())) === "string"
    );
    test("accepts firstName", () =>
      expect(Name.findName(~firstName="Gal", ()))
      |> toMatchRe(Js.Re.fromString("Gal "))
    );
    test("accepts lastName", () =>
      expect(Name.findName(~lastName="Hagever", ()))
      |> toMatchRe(Js.Re.fromString(" Hagever"))
    );
  });

  test(".firstName", () =>
    expect(Js.typeof(Name.firstName())) === "string"
  );
  test(".lastName", () =>
    expect(Js.typeof(Name.lastName())) === "string"
  );
  test(".prefix", () =>
    expect(Js.typeof(Name.prefix())) === "string"
  );
  test(".suffix", () =>
    expect(Js.typeof(Name.suffix())) === "string"
  );
  test(".title", () =>
    expect(Js.typeof(Name.title())) === "string"
  );
  test(".jobArea", () =>
    expect(Js.typeof(Name.jobArea())) === "string"
  );
  test(".jobType", () =>
    expect(Js.typeof(Name.jobType())) === "string"
  );
});
