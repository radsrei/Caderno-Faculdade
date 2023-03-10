package teste;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import static org.junit.Assert.assertEquals;

import java.math.BigInteger;
import java.util.logging.Level;
import java.util.logging.Logger;

import org.junit.Test;

import superfatorial.SuperFatorial;

/**
 * 
 * @author udesc
 */
public class TestFatorial {

	public TestFatorial() {
	}

	@Test
	public void TestSuperFatorialForZeroShouldBeOne() {
		SuperFatorial superFatorial = new SuperFatorial();
		BigInteger resultado = BigInteger.ZERO;

		try {
			resultado = superFatorial.getSuperFatorial(BigInteger.ZERO);
		} catch (exceptions.InputException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		assertEquals(BigInteger.ONE, resultado);
	}

	@Test
	public void TestSuperFatorialForOneShouldBeOne() {
		SuperFatorial superFatorial = new SuperFatorial();
		BigInteger resultado = BigInteger.ZERO;
		try {
			resultado = superFatorial.getSuperFatorial(BigInteger.ONE);
		} catch (exceptions.InputException ex) {
			Logger.getLogger(TestFatorial.class.getName()).log(Level.SEVERE,
					null, ex);
		}
		assertEquals(BigInteger.ONE, resultado);
	}

	@Test
	public void TestSuperFatorialForTwoShouldBeFour() {
		SuperFatorial superFatorial = new SuperFatorial();
		BigInteger resultado = BigInteger.ZERO;
		try {
			resultado = superFatorial.getSuperFatorial(BigInteger.valueOf(2l));
		} catch (exceptions.InputException ex) {
			Logger.getLogger(TestFatorial.class.getName()).log(Level.SEVERE,
					null, ex);
		}
		assertEquals(BigInteger.valueOf(2l), resultado);
	}

	@Test
	public void TestSuperFatorialForFourShouldBe288() {
		SuperFatorial superFatorial = new SuperFatorial();
		BigInteger resultado = BigInteger.ZERO;
		try {
			resultado = superFatorial.getSuperFatorial(BigInteger.valueOf(4l));
		} catch (exceptions.InputException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		assertEquals(BigInteger.valueOf(288l), resultado);
	}

}
