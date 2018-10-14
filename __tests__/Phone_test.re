open Jest;
open Expect;
open! Expect.Operators;

describe("Faker.Phone", () => {
  describe(".phoneNumber", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Phone.phoneNumber())) === "string"
    );
    test("accepts format", () =>
      expect(
        Phone.phoneNumber(~format="###_###_###", ())
        |> Js.String.split("_")
        |> Js.Array.length,
      )
      === 3
    );
  });

  test(".phoneNumberFormat", () =>
    expect(
      Phone.phoneNumberFormat(~phoneFormatsIndex=0)  /* "###-###-####" */
      |> Js.String.split("-")
      |> Js.Array.length,
    )
    === 3
  );

  test(".phoneFormats", () =>
    expect(Js.typeof(Phone.phoneFormats())) === "string"
  );
});
