open Jest;
open Expect;
open! Expect.Operators;

describe("BsFaker.Internet", () => {
  describe(".userName", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Internet.userName())) === "string"
    );
    test("accepts firstName", () =>
      expect(
        Internet.userName(~firstName="joe", ())
        |> Js.String.startsWith("joe"),
      )
      === true
    );
    test("accepts lastName", () =>
      expect(Js.typeof(Internet.userName(~lastName="Jones", ())))
      === "string"
    );
  });
  describe(".email", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Internet.email())) === "string"
    );
    test("accepts firstName", () =>
      expect(
        Internet.email(~firstName="joe", ()) |> Js.String.startsWith("joe"),
      )
      === true
    );
    test("accepts lastName", () =>
      expect(Js.typeof(Internet.email(~lastName="jones", ()))) === "string"
    );
    test("accepts provider", () =>
      expect(
        Internet.email(~provider="domain.org", ())
        |> Js.String.endsWith("domain.org"),
      )
      === true
    );
  });
  describe(".exampleEmail", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Internet.exampleEmail())) === "string"
    );
    test("accepts firstName", () =>
      expect(
        Internet.exampleEmail(~firstName="joe", ())
        |> Js.String.startsWith("joe"),
      )
      === true
    );
    test("accepts lastName", () =>
      expect(Js.typeof(Internet.exampleEmail(~lastName="jones", ())))
      === "string"
    );
    test("contains example domain", () =>
      expect(Internet.exampleEmail() |> Js.String.includes("@example."))
      === true
    );
  });
  test(".avatar", () =>
    expect(Js.typeof(Internet.avatar())) === "string"
  );
  test(".protocol", () =>
    expect(Js.typeof(Internet.protocol())) === "string"
  );
  test(".url", () =>
    expect(Js.typeof(Internet.url())) === "string"
  );
  test(".domainName", () =>
    expect(Js.typeof(Internet.domainName())) === "string"
  );
  test(".domainSuffix", () =>
    expect(Js.typeof(Internet.domainSuffix())) === "string"
  );
  test(".domainWord", () =>
    expect(Js.typeof(Internet.domainWord())) === "string"
  );
  test(".ip", () =>
    expect(Js.typeof(Internet.ip())) === "string"
  );
  test(".ipv6", () =>
    expect(Js.typeof(Internet.ipv6())) === "string"
  );
  test(".userAgent", () =>
    expect(Js.typeof(Internet.userAgent())) === "string"
  );
  test(".mac", () =>
    expect(Js.typeof(Internet.mac())) === "string"
  );
  describe(".color", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Internet.color())) === "string"
    );
    test("accepts color args", () =>
      expect(Js.typeof(Internet.color(~red=255, ~green=255, ~blue=255, ())))
      === "string"
    );
  });
  describe(".password", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Internet.password())) === "string"
    );
    test("accept length", () =>
      expect(Internet.password(~length=8, ()) |> Js.String.length) === 8
    );
    test("accept memorable", () =>
      expect(Js.typeof(Internet.password(~memorable=true, ()))) === "string"
    );
    test("accept pattern", () => {
      let pattern = [%re "/[a-b0-1]+/"];
      expect(Internet.password(~pattern, ()) |> Js.Re.test_(pattern))
      === true;
    });
    test("accept prefix", () =>
      expect(
        Internet.password(~prefix="xxx", ()) |> Js.String.startsWith("xxx"),
      )
      === true
    );
  });
});
