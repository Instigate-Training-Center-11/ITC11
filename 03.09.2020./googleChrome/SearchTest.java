package com.googleChrome;
import org.junit.Test;
import org.openqa.selenium.By;
import org.openqa.selenium.Keys;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.ui.WebDriverWait;
import static org.openqa.selenium.support.ui.ExpectedConditions.presenceOfElementLocated;

public class SearchTest extends WebDriverSettings {

    @Test
    public void serchTest() throws InterruptedException {
        driver.get("https://www.google.com/");
        WebDriverWait wait = new WebDriverWait(driver, 1000);

        driver.manage().window().maximize();
        driver.findElementByName("q").sendKeys("test");
        driver.findElement(By.name("q")).sendKeys("testing" + Keys.ENTER);
        WebElement firstResult = wait.until(presenceOfElementLocated(By.cssSelector("h3")));
        System.out.println((firstResult.getAttribute("textContent").toLowerCase().contains("testing".toLowerCase())));
        System.out.println(firstResult.getText());
    }
}
