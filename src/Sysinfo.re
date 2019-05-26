open Discord;

[@bs.module "process"] external platform: string = "platform";

[@bs.module "os"] external releaseF: unit => string = "release";
let release = releaseF();

let secondsPerDay = 86400;
[@bs.module "os"] external uptimeF: unit => int = "uptime";
let uptime = uptimeF() / secondsPerDay;

let bytesPerGB = 1073741824;
[@bs.module "os"] external totalmemF: unit => int = "totalmem";
let totalmem = totalmemF() / bytesPerGB;

[@bs.module "os"] external freememF: unit => int = "freemem";
let freemem = freememF() / bytesPerGB;

let info = {j|
OS codename: $platform version $release
Uptime: $uptime days
Memory: $freemem / $totalmem GB
Storage: plenty 😂
|j}

Js.log2("sys info", info);

let richInfo = () => {
  open RichEmbed;
  create()
  ->title("Spyder's bot hosting system")
  ->color("DARK_PURPLE")
  ->description(info);
};