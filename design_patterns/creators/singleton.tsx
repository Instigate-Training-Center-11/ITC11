class LogManager {
  private static instance: LogManager;
  private constructor() {}
  public static getInstance(): LogManager {
    if (!this.instance) {
      this.instance = new LogManager();
    }

    return LogManager.instance;
  }
  public error() {
    console.log("Error");
  }
  public warning() {
    console.log("Warning");
  }
  public info() {
    console.log("Info");
  }
}

function clientCode() {
  const log1 = LogManager.getInstance();
  const log2 = LogManager.getInstance();
  log1.error();
  log2.info();
  if (log1 === log2) {
    console.log("Singleton works.");
  } else {
    console.log("Singleton failed.");
  }
}

clientCode();
