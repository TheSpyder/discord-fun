Js.log("Hello, BuckleScript and Reason!");

[@bs.module "../config.json"] external token: string = "token";

open Discord;
let client = Client.createClient();

Client.onReady(
  client,
  _ => {
    Js.log("Bot is ready");
    Client.user(client)->ClientUser.setActivity("Proving spyder doesn't know discord");
  },
);

let reply = (msg, str) => {
  Js.log2("Responding with", str);
  Message.reply(msg, str);
};

let handleMessage = msg => {
  let command =
    (Js.String.substr(Message.content(msg), ~from=1) |> Js.String.split(" "))
    ->Belt.List.fromArray;
  switch (command) {
  | ["ping", ..._] => reply(msg, "pong")
  | ["help", ...request] => reply(msg, Help.help(request))
  | ["calc", ...ops] => reply(msg, Calc.calculate(ops))
  | ["sysinfo", ..._] => Message.channel(msg)->Channel.sendEmbed(Sysinfo.richInfo())
  | _ => () // TODO
  };
};

// immediate filter to ignore bot messages
Client.onMessage(client, msg =>
  switch (
    Message.author(msg)->User.bot,
    Message.content(msg) |> Js.String.indexOf("!"),
    Message.channel(msg)->Channel.name,
  ) {
  | (false, 0, "spyder-reasonml") =>
    Js.log2("Handling command", Message.content(msg));
    handleMessage(msg);
  | (true, _, "spyder-reasonml") => () // ignore bot replies in my channel
  | _ =>
    // this will quickly get spammy hahaha
    // Js.logMany([|
    //   "Unhandled message from",
    //   Message.author(msg)->User.name,
    //   "in Channel",
    //   Message.channel(msg)->Channel.name,
    //   "Contents '" ++ Message.content(msg) ++ "'",
    // |]);
    ();
  }
);

Client.login(client, token);