# Volver a ajustar los datos y corregir los errores previos en el cálculo

# Datos del proyecto
durmientes_por_km = 2000  # (1000m / 0.5m)
km_vias = 2500
durmientes_necesarios = durmientes_por_km * km_vias
durmientes_adicionales = durmientes_necesarios * 0.10
total_durmientes = durmientes_necesarios + durmientes_adicionales

# Distribución anual de provisión de durmientes
provision = {
    2025: 0.10 * durmientes_necesarios,
    2026: 0.20 * durmientes_necesarios,
    2027: 0.30 * durmientes_necesarios,
    2028: 0.40 * durmientes_necesarios + durmientes_adicionales
}

# Costos y precios
costo_durmiente_2024 = 27750
precio_venta_2024 = 34500

inflacion_costos = {
    2025: 0.80,
    2026: 0.45,
    2027: 0.20,
    2028: 0.20
}

inflacion_precios = {
    2025: 0.80,
    2026: 0.45,
    2027: 0.25,
    2028: 0.15
}

# Otros costos
mano_obra_2024 = 667000000
administrativos_2024 = 292000000

ipc = {
    2025: 0.50,
    2026: 0.50,
    2027: 0.50,
    2028: 0.50
}

# Inversión inicial
inversion_inicial = {
    'Terrenos, equipos, maquinarias': 900000000,
    'Tecnología y Software': 325000000,
    'Otros necesarios': 270000000,
    'Organización y gastos administrativos': 360000000
}
amortizacion_anual = 463750000
capital_trabajo = 180000000

# Impuesto a las ganancias
tasa_impuesto = 0.35

# Función para calcular el flujo de caja corregido
def calcular_flujo_caja_corregido():
    flujo_caja = []
    for year in range(2024, 2029):
        if year == 2024:
            inversion = sum(inversion_inicial.values())
            flujo_caja.append(-inversion)
        elif year in provision:
            costo_anual = provision[year] * costo_durmiente_2024 * (1 + inflacion_costos[year-2025])
            precio_anual = precio_venta_2024 * (1 + inflacion_precios[year-2025])
            ingresos = provision[year] * precio_anual
            mano_obra = mano_obra_2024 * (1 + ipc[year-2025])
            administrativos = administrativos_2024 * (1 + ipc[year-2025])
            costos_totales = costo_anual + mano_obra + administrativos
            ebitda = ingresos - costos_totales
            amortizacion = amortizacion_anual
            ebit = ebitda - amortizacion
            impuesto = ebit * tasa_impuesto
            net_income = ebit - impuesto
            flujo_caja.append(net_income + amortizacion)
        else:
            flujo_caja.append(0)  # No hay flujo de caja en años fuera del rango proporcionado

    # Recuperación del capital de trabajo al final del proyecto (año 2028)
    flujo_caja[-1] += capital_trabajo
    return flujo_caja

# Calcular flujo de caja corregido
flujo_caja_corregido = calcular_flujo_caja_corregido()

# Calcular VAN con la tasa de descuento
van_corregido = sum(flujo_caja_corregido[year] / ((1 + tasa_descuento) ** year) for year in range(len(flujo_caja_corregido)))

# Crear DataFrame para exportar
data_corregida = {
    'Año': list(range(2024, 2029)),
    'Flujo de Caja': flujo_caja_corregido
}
#df_corregido = pd.DataFrame(data_corregida)
#df_corregido['VAN Acumulado'] = df_corregido['Flujo de Caja'].cumsum()

#df_corregido.to_excel("/mnt/data/Flujo_Caja_TSB_Corregido.xlsx", index=False)

#van_corregido, df_corregido
