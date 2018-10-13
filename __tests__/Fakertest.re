open Jest;
open Expect;
open! Expect.Operators;

describe("Faker.fake", () => {
  test("returns ok(value) on success", () =>
    expect(
      Faker.fake("Hello {{name.firstName}}")
      |. Belt.Result.getWithDefault("error"),
    )
    |> toMatchRe(Js.Re.fromString("^Hello \\w+$"))
  );

  test("returns error(message) on error", () =>
    expect(
      Faker.fake("Hello {{shouldn't work}}")
      |. Belt.Result.getWithDefault("error"),
    )
    === "error"
  );
});

describe("Faker.Name", () => {
  describe(".findName", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Faker.Name.findName())) === "string"
    );
    test("accepts firstName", () =>
      expect(Faker.Name.findName(~firstName="Gal", ()))
      |> toMatchRe(Js.Re.fromString("Gal "))
    );
    test("accepts lastName", () =>
      expect(Faker.Name.findName(~lastName="Hagever", ()))
      |> toMatchRe(Js.Re.fromString(" Hagever"))
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

describe("Faker.Internet", () => {
  describe(".userName", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Faker.Internet.userName())) === "string"
    );
    test("accepts firstName", () =>
      expect(
        Faker.Internet.userName(~firstName="joe", ()) |> Js.String.startsWith("joe"),
      )
      === true
    );
    test("accepts lastName", () =>
      expect(Js.typeof(Faker.Internet.userName(~lastName="Jones", ()))) === "string"
    );
  });
  describe(".email", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Faker.Internet.email())) === "string"
    );
    test("accepts firstName", () =>
      expect(
        Faker.Internet.email(~firstName="joe", ()) |> Js.String.startsWith("joe"),
      )
      === true
    );
    test("accepts lastName", () =>
      expect(Js.typeof(Faker.Internet.email(~lastName="jones", ()))) === "string"
    );
    test("accepts provider", () =>
      expect(
        Faker.Internet.email(~provider="domain.org", ())
        |> Js.String.endsWith("domain.org"),
      )
      === true
    );
  });
  describe(".exampleEmail", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Faker.Internet.exampleEmail())) === "string"
    );
    test("accepts firstName", () =>
      expect(
        Faker.Internet.exampleEmail(~firstName="joe", ())
        |> Js.String.startsWith("joe"),
      )
      === true
    );
    test("accepts lastName", () =>
      expect(Js.typeof(Faker.Internet.exampleEmail(~lastName="jones", ())))
      === "string"
    );
    test("contains example domain", () =>
      expect(Faker.Internet.exampleEmail() |> Js.String.includes("@example.")) === true
    );
  });
  test(".avatar", () =>
    expect(Js.typeof(Faker.Internet.avatar())) === "string"
  );
  test(".protocol", () =>
    expect(Js.typeof(Faker.Internet.protocol())) === "string"
  );
  test(".url", () =>
    expect(Js.typeof(Faker.Internet.url())) === "string"
  );
  test(".domainName", () =>
    expect(Js.typeof(Faker.Internet.domainName())) === "string"
  );
  test(".domainSuffix", () =>
    expect(Js.typeof(Faker.Internet.domainSuffix())) === "string"
  );
  test(".domainWord", () =>
    expect(Js.typeof(Faker.Internet.domainWord())) === "string"
  );
  test(".ip", () =>
    expect(Js.typeof(Faker.Internet.ip())) === "string"
  );
  test(".ipv6", () =>
    expect(Js.typeof(Faker.Internet.ipv6())) === "string"
  );
  test(".userAgent", () =>
    expect(Js.typeof(Faker.Internet.userAgent())) === "string"
  );
  test(".mac", () =>
    expect(Js.typeof(Faker.Internet.mac())) === "string"
  );
  describe(".color", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Faker.Internet.color())) === "string"
    );
    test("accepts color args", () =>
      expect(Js.typeof(Faker.Internet.color(~red=255, ~green=255, ~blue=255, ())))
      === "string"
    );
  });
  describe(".password", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Faker.Internet.password())) === "string"
    );
    test("accept length", () =>
      expect(Faker.Internet.password(~length=8, ()) |> Js.String.length) === 8
    );
    test("accept memorable", () =>
      expect(Js.typeof(Faker.Internet.password(~memorable=true, ()))) === "string"
    );
    test("accept pattern", () => {
      let pattern = [%re "/[a-b0-1]+/"];
      expect(Faker.Internet.password(~pattern, ()) |. Js.Re.test(pattern)) === true;
    });
    test("accept prefix", () =>
      expect(
        Faker.Internet.password(~prefix="xxx", ()) |> Js.String.startsWith("xxx"),
      )
      === true
    );
  });
});

describe("Faker.Image", () => {
  test(".avatar", () =>
    expect(Js.typeof(Faker.Image.avatar())) === "string"
  );
  test(".abstract", () =>
    expect(Js.typeof(Faker.Image.abstract())) === "string"
  );
  test(".animals", () =>
    expect(Js.typeof(Faker.Image.animals())) === "string"
  );
  test(".business", () =>
    expect(Js.typeof(Faker.Image.business())) === "string"
  );
  test(".cats", () =>
    expect(Js.typeof(Faker.Image.cats())) === "string"
  );
  test(".city", () =>
    expect(Js.typeof(Faker.Image.city())) === "string"
  );
  test(".dataUri", () =>
    expect(Js.typeof(Faker.Image.dataUri())) === "string"
  );
  test(".fashion", () =>
    expect(Js.typeof(Faker.Image.fashion())) === "string"
  );
  test(".food", () =>
    expect(Js.typeof(Faker.Image.food())) === "string"
  );
  test(".image", () =>
    expect(Js.typeof(Faker.Image.image())) === "string"
  );
  test(".imageUrl", () =>
    expect(Js.typeof(Faker.Image.imageUrl())) === "string"
  );
  test(".natrue", () =>
    expect(Js.typeof(Faker.Image.nature())) === "string"
  );
  test(".nightlife", () =>
    expect(Js.typeof(Faker.Image.nightlife())) === "string"
  );
  test(".people", () =>
    expect(Js.typeof(Faker.Image.people())) === "string"
  );
  test(".sports", () =>
    expect(Js.typeof(Faker.Image.sports())) === "string"
  );
  test(".technics", () =>
    expect(Js.typeof(Faker.Image.technics())) === "string"
  );
  test(".transport  ", () =>
    expect(Js.typeof(Faker.Image.transport())) === "string"
  );
});

describe("Faker.Lorem", () => {
  test(".word", () =>
    expect(Js.typeof(Faker.Lorem.word())) === "string"
  );
  describe(".words", () => {
    test("accepts optional args", () => {
      expect(Js.typeof(Faker.Lorem.words())) === "string"
    });
    test("accepts wordCount", () => {
      expect(
        Faker.Lorem.words(~wordCount=3, ())
        |> Js.String.split(" ")
        |> Js.Array.length
      ) === 3
    });
  });
  describe(".sentence", () => {
    test("accepts optional args", () => {
      expect(Js.typeof(Faker.Lorem.sentence())) === "string"
    });
    test("accepts wordCount", () => {
      expect(
        Faker.Lorem.sentence(~wordCount=3, ())
        |> Js.String.split(" ")
        |> Js.Array.length
      ) === 3
    });
  });
  describe(".slug", () => {
    test("accepts optional args", () => {
      expect(Js.typeof(Faker.Lorem.slug())) === "string"
    });
    test("accepts wordCount", () => {
      expect(
        Faker.Lorem.slug(~wordCount=3, ())
        |> Js.String.split("-")
        |> Js.Array.length
      ) === 3
    });
  });
  describe(".sentences", () => {
    test("accepts optional args", () => {
      expect(Js.typeof(Faker.Lorem.sentences())) === "string"
    });
    test("accepts sentenceCount", () => {
      expect(
        Faker.Lorem.sentences(~sentenceCount=3, ())
        |> Js.String.split(".")
        |> Js.Array.length
      ) === 4 /* because the last sentence also ends with a period */
    });
    test("accepts separator", () => {
      expect(
        Faker.Lorem.sentences(~sentenceCount=3, ~separator=";;", ())
        |> Js.String.split(";;")
        |> Js.Array.length
      ) === 3
    });
  });
  describe("paragraph", () => {
    test("acepts optional args", () => {
      expect(Js.typeof(Faker.Lorem.paragraph())) === "string"
    });
    test("accepts sentenceCount", () => {
      expect(
        Faker.Lorem.paragraph(~sentenceCount=3, ())
        |> Js.String.split(".")
        |> Js.Array.length
      ) >= 4 /* because the last sentence also ends with a period, but also paragraph inexplicably adds up to 3 additional sentences */
    });
  });
  describe("paragraphs", () => {
    test("acepts optional args", () => {
      expect(Js.typeof(Faker.Lorem.paragraphs())) === "string"
    });
    test("accepts paragraphCount", () => {
      expect(
        Faker.Lorem.paragraphs(~paragraphCount=3, ())
        |> Js.String.split("\n \r")
        |> Js.Array.length
      ) === 3
    });
    test("accepts separator", () => {
      expect(
        Faker.Lorem.paragraphs(~paragraphCount=3, ~separator=";;;", ())
        |> Js.String.split(";;;")
        |> Js.Array.length
      ) === 3
    });
  });
  test("text", () =>
    expect(Js.typeof(Faker.Lorem.text())) === "string"
  );
  describe("lines", () => {
    test("accepts optional args", () => {
      expect(Js.typeof(Faker.Lorem.lines())) === "string"
    });
    test("accepts lineCount", () => {
      expect(
        Faker.Lorem.lines(~lineCount=3, ())
        |> Js.String.split("\n")
        |> Js.Array.length
      ) === 3
    });
  });
});

describe("Faker.Company", () => {
  test("suffixes", () => {
    expect(Js.Array.isArray(Faker.Company.suffixes())) === true
  });
  describe("companyName", () => {
    test("accepts optional args", () => {
      expect(Js.typeof(Faker.Company.companyName())) === "string"
    });
    test("accepts format", () => {
      expect(
        Faker.Company.companyName(~format=1, ())
        |> Js.String.split(" - ") /* format 1 is "something - something" */
        |> Js.Array.length
      ) === 2;
    });
  });
  test("companySuffix", () => {
    expect(Js.typeof(Faker.Company.companySuffix())) === "string"
  });
  test("catchPhrase", () => {
    expect(Js.typeof(Faker.Company.catchPhrase())) === "string"
  });
  test("bs", () => {
    expect(Js.typeof(Faker.Company.bs())) === "string"
  });
  test("catchPhraseAdjective", () => {
    expect(Js.typeof(Faker.Company.catchPhraseAdjective())) === "string"
  });
  test("catchPhraseDescriptor", () => {
    expect(Js.typeof(Faker.Company.catchPhraseDescriptor())) === "string"
  });
  test("catchPhraseNoun", () => {
    expect(Js.typeof(Faker.Company.catchPhraseNoun())) === "string"
  });
  test("bsAdjective", () => {
    expect(Js.typeof(Faker.Company.bsAdjective())) === "string"
  });
  test("bsBuzz", () => {
    expect(Js.typeof(Faker.Company.bsBuzz())) === "string"
  });
  test("bsNoun", () => {
    expect(Js.typeof(Faker.Company.bsNoun())) === "string"
  });
});

describe("Faker.Phone", () => {
  describe(".phoneNumber", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Faker.Phone.phoneNumber())) === "string"
    );
    test("accepts format", () =>
      expect(
        Faker.Phone.phoneNumber(~format="###_###_###", ())
        |> Js.String.split("_")
        |> Js.Array.length,
      )
      === 3
    );
  });

  test(".phoneNumberFormat", () =>
    expect(
      Faker.Phone.phoneNumberFormat(~phoneFormatsIndex=0)  /* "###-###-####" */
      |> Js.String.split("-")
      |> Js.Array.length,
    )
    === 3
  );

  test(".phoneFormats", () =>
    expect(Js.typeof(Faker.Phone.phoneFormats())) === "string"
  );
});