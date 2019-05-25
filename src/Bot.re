Js.log("Hello, BuckleScript and Reason!");

[@bs.module "../../../config.json"] external token : string = "token";
[@bs.module "../../../config.json"] external prefix : string = "prefix";

open Discord;
let client = Client.createClient();

Client.onReady(client, _ => Js.log("Bot is ready"));

let handleMessage = msg =>
  switch (Message.author(msg) -> User.bot, Message.content(msg)) {
  | (false, _) => ()
  | (_, "ping") => Message.reply(msg, "pong")
  | _ => () // TODO
  };

Client.onMessage(client, handleMessage);

Client.login(client, token);